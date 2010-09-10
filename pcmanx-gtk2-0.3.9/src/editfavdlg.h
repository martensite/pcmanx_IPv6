/**
 * Copyright (c) 2005 PCMan <pcman.tw@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef EDITFAVDLG_H
#define EDITFAVDLG_H

#ifdef __GNUG__
  #pragma interface "editfavdlg.h"
#endif

#include "dialog.h"

#include <vector>
using namespace std;

/**
@author PCMan
*/
class CSite;
class CListBox;
class CEditFavDlg : public CDialog
{
public:
    CEditFavDlg(CWidget* parent, vector<CSite>& sites);

    static void OnAdd(GtkWidget* btn, CEditFavDlg* _this);
    static void OnEdit(GtkWidget* btn, CEditFavDlg* _this);
    static void OnRemove(GtkWidget* btn, CEditFavDlg* _this);
    static void OnUp(GtkWidget* btn, CEditFavDlg* _this);
    static void OnDown(GtkWidget* btn, CEditFavDlg* _this);
    static void OnRowActivated(GtkTreeView *tree_view, GtkTreePath* path,  
	GtkTreeViewColumn* col, CEditFavDlg* _this);

	vector<CSite>& m_Sites;
    CListBox* m_List;
	GtkWidget* m_EditBtn;
protected:
};

#endif
