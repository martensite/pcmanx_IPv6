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

#ifndef LISTBOX_H
#define LISTBOX_H

#ifdef __GNUG__
  #pragma interface "listbox.h"
#endif

#include <gtk/gtk.h>
#include <widget.h>
#include <string>

using namespace std;

/**
@author PCMan
*/
class CListBox : public CWidget
{
public:
    CListBox();

	int Count() {	return gtk_tree_model_iter_n_children(GTK_TREE_MODEL(m_Store), NULL);	}
    void Append(string text);
    void Insert(int pos, string text);

    void Delete(GtkTreeIter* iter){	gtk_list_store_remove(m_Store, iter);	}
    void Delete(int idx);

    void MoveUp(int idx);
    void MoveDown(int idx);

    int GetCurSel();
    void SetItemText(int idx, string text);
    string GetItemText(int idx);
	void SetCurSel(int idx);

	GtkTreeModel* GetTreeModel(){	return GTK_TREE_MODEL(m_Store);	}
	GtkTreeView* GetTreeView(){	return GTK_TREE_VIEW(m_Widget);	}
protected:
    GtkListStore* m_Store;
};

#endif
