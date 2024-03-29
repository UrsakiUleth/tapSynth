/*
  ==============================================================================

    AdsrComponent.h
    Created: 18 Jan 2024 5:07:33pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::AudioProcessorValueTreeState& apvts);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    void setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    // This just makes code cleaner
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;

    juce::Label attackLabel { "Attack", "A" };
    juce::Label decayLabel { "Decay", "D" };
    juce::Label sustainLabel { "Sustain", "S" };
    juce::Label releaseLabel { "Release", "R" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
