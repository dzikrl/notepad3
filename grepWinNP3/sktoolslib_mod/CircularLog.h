// sktoolslib - common files for SK tools

// Copyright (C) 2013, 2020-2021 - Stefan Kueng

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
#include <list>
#include <mutex>
#include <string>

class CCircularLog
{
private:
    CCircularLog();
    ~CCircularLog();

public:
    static CCircularLog& Instance();

    bool         Init(const std::wstring& path, int maxlines);
    bool         AddLine(const std::wstring& line);
    bool         Save();
    std::wstring GetSavePath() const { return m_path; }

    // Unicode output helper
    void operator()(LPCWSTR pszFormat, ...);

private:
    std::list<std::wstring> m_lines;
    std::wstring            m_path;
    int                     m_maxLines;
    std::mutex              m_mutex;
};
