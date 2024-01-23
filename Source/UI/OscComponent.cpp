/*
  ==============================================================================

    OscComponent.cpp
    Created: 19 Jan 2024 2:17:33pm
    Author:  Matthew

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorID, juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray choices {"Sine", "Square", "Saw"};
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);

    oscWaveSelectorAttachment = std::make_unique <juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorID, oscWaveSelector);

    setSliderWithLabel(fmFreqSlider, fmFreqLabel, apvts, fmFreqId, fmFreqAttachment);
    setSliderWithLabel(fmDepthSlider, fmDepthLabel, apvts, fmDepthId, fmDepthAttachment);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void OscComponent::resized()
{
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    const auto sliderPosY = 80;


    oscWaveSelector.setBounds(0, 0, 90, 20);
    fmFreqSlider.setBounds(0, sliderPosY, sliderWidth, sliderHeight);
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - labelYOffset, fmFreqSlider.getWidth(), labelHeight);
    fmDepthSlider.setBounds(fmFreqSlider.getRight(), sliderPosY, sliderWidth, sliderHeight);
    fmDepthLabel.setBounds(fmDepthSlider.getX(), fmDepthSlider.getY() - labelYOffset, fmDepthSlider.getWidth(), labelHeight);
}

using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void OscComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId,
    std::unique_ptr <Attachment>& attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);

    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}