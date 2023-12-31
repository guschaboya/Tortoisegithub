﻿// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2008-2011, 2015-2017, 2019-2020, 2023 - TortoiseGit

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

#include "GitRevLoglist.h"
#include "GestureEnabledControl.h"
#include "DockablePaneUnscaledStoredState.h"

class CPropertiesToolBar : public CMFCToolBar
{
public:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) override
	{
		CMFCToolBar::OnUpdateCmdUI(static_cast<CFrameWnd*>(GetOwner()), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const override { return FALSE; }
};

class CPropertiesWnd : public CDockablePaneUnscaledStoredState
{
// Construction
public:
	CPropertiesWnd();

	void AdjustLayout();

// Attributes
public:
	void SetVSDotNetLook(BOOL bSet)
	{
		m_wndPropList.SetVSDotNetLook(bSet);
		m_wndPropList.SetGroupNameFullWidth(bSet);
	}

	// rev=nullptr, means clear properties info;
	void UpdateProperties(GitRevLoglist* rev = nullptr);

protected:
	CFont m_fntPropList;
	CGestureEnabledControlTmpl<CMFCPropertyGridCtrl> m_wndPropList;

	void RemoveParent();
// Implementation
public:
	virtual ~CPropertiesWnd();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSettingChange(UINT uFlags, LPCWSTR lpszSection);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	DECLARE_MESSAGE_MAP()

	void InitPropList();
	void SetPropListFont();

	CMFCPropertyGridProperty* m_CommitHash = nullptr;
	CMFCPropertyGridProperty* m_AuthorName = nullptr;
	CMFCPropertyGridProperty* m_AuthorDate = nullptr;
	CMFCPropertyGridProperty* m_AuthorEmail = nullptr;

	CMFCPropertyGridProperty* m_CommitterName = nullptr;
	CMFCPropertyGridProperty* m_CommitterEmail = nullptr;
	CMFCPropertyGridProperty* m_CommitterDate = nullptr;

	CMFCPropertyGridProperty* m_Subject = nullptr;
	CMFCPropertyGridProperty* m_Body = nullptr;

	CMFCPropertyGridProperty* m_ParentGroup = nullptr;
	CMFCPropertyGridProperty* m_BaseInfoGroup = nullptr;

	std::vector<CMFCPropertyGridProperty*> m_ParentHash;
	std::vector<CMFCPropertyGridProperty*> m_ParentSubject;

	void SetTheme(bool bDark);
	int m_themeCallbackId = 0;
};
