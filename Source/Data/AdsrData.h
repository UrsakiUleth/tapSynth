/*
  ==============================================================================

    AdsrData.h
    Created: 18 Jan 2024 5:08:08pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);

private:
    juce::ADSR::Parameters adsrParams;
};
