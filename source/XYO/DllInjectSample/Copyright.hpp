// Dll Inject Sample
// Copyright (c) 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_DLLINJECTSAMPLE_COPYRIGHT_HPP
#define XYO_DLLINJECTSAMPLE_COPYRIGHT_HPP

#ifndef XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP
#	include <XYO/DllInjectSample/Dependency.hpp>
#endif

namespace XYO::DllInjectSample::Copyright {
	XYO_DLLINJECTSAMPLE_EXPORT const char *copyright();
	XYO_DLLINJECTSAMPLE_EXPORT const char *publisher();
	XYO_DLLINJECTSAMPLE_EXPORT const char *company();
	XYO_DLLINJECTSAMPLE_EXPORT const char *contact();
};

#endif
