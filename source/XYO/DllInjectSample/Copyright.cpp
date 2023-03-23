// Dll Inject Sample
// Copyright (c) 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2014-2023 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <XYO/DllInjectSample/Copyright.hpp>
#include <XYO/DllInjectSample/Copyright.rh>

namespace XYO::DllInjectSample::Copyright {

	static const char *copyright_ = XYO_DLLINJECTSAMPLE_COPYRIGHT;
	static const char *publisher_ = XYO_DLLINJECTSAMPLE_PUBLISHER;
	static const char *company_ = XYO_DLLINJECTSAMPLE_COMPANY;
	static const char *contact_ = XYO_DLLINJECTSAMPLE_CONTACT;

	const char *copyright() {
		return copyright_;
	};

	const char *publisher() {
		return publisher_;
	};

	const char *company() {
		return company_;
	};

	const char *contact() {
		return contact_;
	};

};
