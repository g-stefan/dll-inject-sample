// Dll Inject Sample
// Copyright (c) 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP
#define XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP

#ifndef XYO_WININJECT_HPP
#	include <XYO/WinInject.hpp>
#endif

// -- Export

#ifdef XYO_DLLINJECTSAMPLE_INTERNAL
#	define XYO_DLLINJECTSAMPLE_EXPORT XYO_LIBRARY_EXPORT
#else
#	define XYO_DLLINJECTSAMPLE_EXPORT XYO_LIBRARY_IMPORT
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
