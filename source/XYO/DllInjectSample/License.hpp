// Dll Inject Sample
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_DLLINJECTSAMPLE_LICENSE_HPP
#define XYO_DLLINJECTSAMPLE_LICENSE_HPP

#ifndef XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP
#	include <XYO/DllInjectSample/Dependency.hpp>
#endif

namespace XYO::DllInjectSample::License {

	XYO_DLLINJECTSAMPLE_EXPORT const char *license();
	XYO_DLLINJECTSAMPLE_EXPORT const char *shortLicense();

};

#endif
