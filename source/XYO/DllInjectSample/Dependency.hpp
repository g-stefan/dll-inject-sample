// Dll Inject Sample
// Copyright (c) 2014-2025 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2025 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP
#define XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP

#ifndef XYO_WININJECT_HPP
#	include <XYO/WinInject.hpp>
#endif

// -- Export

#ifdef DLL_INJECT_SAMPLE_INTERNAL
#	define XYO_DLLINJECTSAMPLE_INTERNAL
#endif

#ifdef XYO_DLLINJECTSAMPLE_INTERNAL
#	define XYO_DLLINJECTSAMPLE_EXPORT XYO_PLATFORM_LIBRARY_EXPORT
#else
#	define XYO_DLLINJECTSAMPLE_EXPORT XYO_PLATFORM_LIBRARY_IMPORT
#endif
#ifdef XYO_DLLINJECTSAMPLE_LIBRARY
#	undef XYO_DLLINJECTSAMPLE_EXPORT
#	define XYO_DLLINJECTSAMPLE_EXPORT
#endif

// --

namespace XYO::DllInjectSample {
	using namespace XYO::ManagedMemory;
	using namespace XYO::DataStructures;
	using namespace XYO::Encoding;
	using namespace XYO::Multithreading;
	using namespace XYO::System;
	using namespace XYO::Win;
	using namespace XYO::Win::Inject;
};

#endif
