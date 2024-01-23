/*
  ==============================================================================

    OscData.cpp
    Created: 19 Jan 2024 12:58:12pm
    Author:  Matthew

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    fmOsc.prepare(spec);
    prepare(spec);
}

void OscData::setWaveType(const int choice)
{
    /*
    // Sine Wave
    juce::dsp::Oscillator<float> SineOsc{ [](float x) { return std::sin(x); } };
    // Square Wave
    juce::dsp::Oscillator<float> SquareOsc { [](float x) { return x < 0.0f ? -1.0f : 1.0f; }, 200};
    // Sawtooth Wave
    juce::dsp::Oscillator<float> SawtoothOsc { [](float y) {return y / juce::MathConstants<float>::pi;  } };
    */

    switch (choice) {
    case 0:
        // Sine
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:
        // Square
        initialise ( [](float y) { return y < 0.0f ? -1.0f : 1.0f; } );
        break;
    case 2:
        // Sawtooth
        initialise( [](float y) {return y / juce::MathConstants<float>::pi;  } );
        break;
    default:
        jassertfalse; // You're not supposed to be here
        break;
    }
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample(block.getSample(ch, s)) * fmDepth; // getting the value of the wave a particular point in time
        }
    }

    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setFmParams(const float depth, const float freq)
{
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod;
    setFrequency(currentFreq >= 0 ? currentFreq : currentFreq * -1.0);
}