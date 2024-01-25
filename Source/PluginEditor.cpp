/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapSynthAudioProcessorEditor::TapSynthAudioProcessorEditor (TapSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), 
    audioProcessor (p), 
    osc (audioProcessor.apvts, "OSC1WAVETYPE", "FMFREQ", "FMDEPTH"),
    adsr(audioProcessor.apvts), 
    filter (audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES")
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 500);


    addAndMakeVisible(adsr);
    addAndMakeVisible(osc);
    addAndMakeVisible(filter);
}

TapSynthAudioProcessorEditor::~TapSynthAudioProcessorEditor()
{
}

//==============================================================================
void TapSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);
}

void TapSynthAudioProcessorEditor::resized()
{
    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 235;


    osc.setBounds(paddingX, paddingY, 300, 200);
    adsr.setBounds(osc.getRight(), paddingY, 280, 200);
    filter.setBounds(paddingX, paddingY2, 300, 200);
}
