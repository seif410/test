//
// pch.h
//

#pragma once

#include <collection.h>
#include <ppltasks.h>

#include "App.xaml.h"
#include"User.h"

static class func {

public:
	
	static std::string toStd(Platform::String^ ms)
	{
		std::wstring w_str(ms->Begin());
		return std::string(w_str.begin(), w_str.end());
	}

	static Platform::String^ toPF(const std::string& input)
	{
		std::wstring w_str = std::wstring(input.begin(), input.end());
		const wchar_t* w_chars = w_str.c_str();
		return (ref new Platform::String(w_chars));
	}
};
