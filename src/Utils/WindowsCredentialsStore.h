﻿// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2016, 2018-2020, 2023 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#pragma once

class CCredentials;

class CWindowsCredentialsStore {
private:
	CWindowsCredentialsStore() = delete;

public:
	static int GetCredential(const CString& entryName, CCredentials& credentials);
	static int SaveCredential(const CString& entryName, const CString& username, const wchar_t* password);
	static int DeleteCredential(const CString& entryName);
	static int ListCredentials(const CString& startsWith, CStringList& result);
};

class CCredentials {
public:
	CCredentials();
	~CCredentials();

	CString m_username;
	wchar_t m_password[256]{};

	friend class CWindowsCredentialsStore;

	CCredentials(CCredentials&) = delete;
	CCredentials(CCredentials&& that) = default;
	CCredentials& operator=(const CCredentials&) = delete;
};
