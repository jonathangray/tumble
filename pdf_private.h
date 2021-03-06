/*
 * tumble: build a PDF file from image files
 *
 * PDF routines
 * Copyright 2001, 2002, 2003, 2017 Eric Smith <spacewar@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.  Note that permission is
 * not granted to redistribute this program under the terms of any
 * other version of the General Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 */


struct pdf_page
{
  pdf_file_handle pdf_file;
  struct pdf_obj *page_dict;
  struct pdf_obj *media_box;
  struct pdf_obj *procset;
  struct pdf_obj *resources;

  char last_XObject_name;
  struct pdf_obj *XObject_dict;
};


struct pdf_pages
{
  struct pdf_obj *pages_dict;
  struct pdf_obj *kids;
  struct pdf_obj *count;
};


struct pdf_file
{
  FILE                 *f;
  struct pdf_obj       *first_ind_obj;
  struct pdf_obj       *last_ind_obj;
  long int              xref_offset;
  struct pdf_obj       *catalog;
  struct pdf_obj       *info;
  struct pdf_pages     *root;
  struct pdf_bookmark  *outline_root;
  struct pdf_obj       *trailer_dict;
  struct pdf_name_tree *page_label_tree;
  struct pdf_name_tree *name_tree_list;
};
