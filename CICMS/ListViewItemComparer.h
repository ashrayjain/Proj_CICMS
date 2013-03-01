
/*************************************************************************************************/
//
//  ListViewItemComparer.h
//
//  Description: [for MainForm's ListView components] A simple class that implements the manual sorting of items by columns. 
//
//  API:
//  CICMS_UI::ListViewItemComparer::ListViewItemComparer(int column, bool sortOrder);
//	CICMS_UI::ListViewItemComparer::Compare(Object^ x, Object^ y);
//
//  Main authors: XIE KAI(A0102016E)
//
/*************************************************************************************************/
//
#ifndef _GUARD_UI_ListViewItemComparer
#define _GUARD_UI_ListViewItemComparer

namespace CICMS_UI {
	ref class ListViewItemComparer: public System::Collections::IComparer
	{
	public: ListViewItemComparer(int column, bool sortOrder, bool is_num);

	private: int _col;
	private: bool _sort;
	private: bool _is_num;

	public: virtual int Compare(Object^ x, Object^ y);
	private: int Compare_s(System::String^ s1, System::String^ s2);
	};
}
#endif