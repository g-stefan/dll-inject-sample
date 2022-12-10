// Dll Inject Sample
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#ifndef XYO_DLLINJECTSAMPLE_VERSION_HPP
#define XYO_DLLINJECTSAMPLE_VERSION_HPP

#ifndef XYO_DLLINJECTSAMPLE_DEPENDENCY_HPP
#	include <XYO/DllInjectSample/Dependency.hpp>
#endif

namespace XYO::DllInjectSample::Version {

	XYO_DLLINJECTSAMPLE_EXPORT const char *version();
	XYO_DLLINJECTSAMPLE_EXPORT const char *build();
	XYO_DLLINJECTSAMPLE_EXPORT const char *versionWithBuild();
	XYO_DLLINJECTSAMPLE_EXPORT const char *datetime();

};

#endif
