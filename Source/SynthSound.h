/*
  ==============================================================================

    SynthSound.h
    Created: 15 Jan 2024 10:37:26am
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiNotChannel) override { return true; }
};