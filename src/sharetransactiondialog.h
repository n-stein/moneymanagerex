/*******************************************************
 Copyright (C) 2020 Nikolay Akimov

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/
#pragma once

#include "defs.h"
#include "mmTextCtrl.h"
#include "model/Model_Stock.h"
#include <wx/webview.h>

class ShareTransactionDialog : public wxDialog
{
public:
    ShareTransactionDialog(wxWindow* parent, int64 acc, int64 id, int64 ticker_id, int type = 0);

    ~ShareTransactionDialog();
    int64 get_id() const;

private:
    void CreateControls();
    void OnOk(wxCommandEvent& event);
    void OnQuit(wxCloseEvent& event);

    int64 m_id;
    int64 m_acc;
    int m_type;
    int m_share_precision;
    int64 m_ticker_id;
    wxChoice* m_choiceType;

    wxDatePickerCtrl* m_purchase_date_ctrl;
    mmTextCtrl* m_num_shares_ctrl;
    mmTextCtrl* m_purchase_price_ctrl;
    mmTextCtrl* m_commission_ctrl;
    mmTextCtrl* m_stock_symbol_ctrl;
    mmTextCtrl* m_lot_ctrl;
    mmTextCtrl* m_notes_ctrl;
    wxWebView* browser_;
    wxBitmapButton* m_attachments_btn;

    void OnTextEntered(wxCommandEvent& event);
    void OnAttachments(wxCommandEvent& event);
    void OnOrganizeAttachments(wxCommandEvent& event);
    void fillControls();

    wxDECLARE_EVENT_TABLE();

    enum
    {
        ID_STOCK_DATE = wxID_HIGHEST + 800,
        ID_TEXTCTRL_NUMBER_SHARES,
        ID_TEXTCTRL_STOCK_PP,
        ID_TEXTCTRL_STOCK_COMMISSION,
        ID_TEXTCTRL_LOT
    };
};

inline int64 ShareTransactionDialog::get_id() const
{
    return m_id;
}
