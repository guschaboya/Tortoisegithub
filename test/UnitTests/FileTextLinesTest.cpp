﻿// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2016, 2023 - TortoiseGit

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

#include "stdafx.h"
#include "FileTextLines.h"

TEST(CFileTextLines, CheckUnicodeType)
{
	constexpr char ascii[] = "some text";
	// This text contains the umlaut "ä".
	constexpr unsigned char ansi[] = { 0x54, 0x68, 0x69, 0x73, 0x20, 0x74, 0x65, 0x78, 0x74, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x75, 0x6D, 0x6C, 0x61, 0x75, 0x74, 0x20, 0x22, 0xE4, 0x22, 0x2E };
	constexpr unsigned char utf8[] = { 0x54, 0x68, 0x69, 0x73, 0x20, 0x74, 0x65, 0x78, 0x74, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x75, 0x6D, 0x6C, 0x61, 0x75, 0x74, 0x20, 0x22, 0xC3, 0xA4, 0x22, 0x2E };
	constexpr unsigned char utf8bom[] = { 0xEF, 0xBB, 0xBF, 0x54, 0x68, 0x69, 0x73, 0x20, 0x74, 0x65, 0x78, 0x74, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69, 0x6E, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x75, 0x6D, 0x6C, 0x61, 0x75, 0x74, 0x20, 0x22, 0xC3, 0xA4, 0x22, 0x2E };
	constexpr unsigned char utf16be[] = { 0x00, 0x54, 0x00, 0x68, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x65, 0x00, 0x78, 0x00, 0x74, 0x00, 0x20, 0x00, 0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x20, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x6C, 0x00, 0x61, 0x00, 0x75, 0x00, 0x74, 0x00, 0x20, 0x00, 0x22, 0x00, 0xE4, 0x00, 0x22, 0x00, 0x2E };
	constexpr unsigned char utf16bebom[] = { 0xFE, 0xFF, 0x00, 0x54, 0x00, 0x68, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x65, 0x00, 0x78, 0x00, 0x74, 0x00, 0x20, 0x00, 0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x20, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x6C, 0x00, 0x61, 0x00, 0x75, 0x00, 0x74, 0x00, 0x20, 0x00, 0x22, 0x00, 0xE4, 0x00, 0x22, 0x00, 0x2E };
	constexpr unsigned char utf16le[] = { 0x54, 0x00, 0x68, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x65, 0x00, 0x78, 0x00, 0x74, 0x00, 0x20, 0x00, 0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x20, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x6C, 0x00, 0x61, 0x00, 0x75, 0x00, 0x74, 0x00, 0x20, 0x00, 0x22, 0x00, 0xE4, 0x00, 0x22, 0x00, 0x2E, 0x00 };
	constexpr unsigned char utf16lebom[] = { 0xFF, 0xFE, 0x54, 0x00, 0x68, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x65, 0x00, 0x78, 0x00, 0x74, 0x00, 0x20, 0x00, 0x63, 0x00, 0x6F, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x73, 0x00, 0x20, 0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x20, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x6C, 0x00, 0x61, 0x00, 0x75, 0x00, 0x74, 0x00, 0x20, 0x00, 0x22, 0x00, 0xE4, 0x00, 0x22, 0x00, 0x2E, 0x00 };

	CFileTextLines ftl;
	EXPECT_EQ(CFileTextLines::UnicodeType::ASCII, ftl.CheckUnicodeType(ascii, sizeof(ascii) - 1));
	EXPECT_EQ(CFileTextLines::UnicodeType::ASCII, ftl.CheckUnicodeType(ansi, sizeof(ansi)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF8, ftl.CheckUnicodeType(utf8, sizeof(utf8)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF8BOM, ftl.CheckUnicodeType(utf8bom, sizeof(utf8bom)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF16_BE, ftl.CheckUnicodeType(utf16be, sizeof(utf16be)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF16_BEBOM, ftl.CheckUnicodeType(utf16bebom, sizeof(utf16bebom)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF16_LE, ftl.CheckUnicodeType(utf16le, sizeof(utf16le)));
	EXPECT_EQ(CFileTextLines::UnicodeType::UTF16_LEBOM, ftl.CheckUnicodeType(utf16lebom, sizeof(utf16lebom)));
}
