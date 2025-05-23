#pragma once
#include "utils.h"
#include <map>

enum Mood {
	Sad = 1,
	Frustrated,
	Neutral,
	Happy,
	Calm
};
Mood getMood();
static map<Mood, string> moodMap{
		{Sad, "Sad"},
		{Frustrated, "Frustrated"},
		{Neutral, "Neutral"},
		{Happy, "Happy"},
		{Calm, "Calm"}
};