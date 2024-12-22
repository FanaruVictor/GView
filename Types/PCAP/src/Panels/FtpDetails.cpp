#include "PCAP.hpp"

using namespace GView::Type::PCAP;
using namespace GView::Type::PCAP::Panels;
using namespace AppCUI::Controls;
using namespace AppCUI::OS;

FtpDetails::FtpDetails(Reference<Object> _object, Reference<GView::Type::PCAP::PCAPFile> _pcap)
    : TabPage("Ftp Deta&ils")
{
    pcap   = _pcap;
    object = _object;

    details = CreateChildControl<ListView>(
        "x:0,y:0,w:100%,h:10",
        std::initializer_list<ConstString>{ "n:Field,w:24", "n:Value,w:100" },
        ListViewFlags::None
    );

    Update();
}

// Populates the details information section
void FtpDetails::UpdateFtpDetailsInformation()
{
    LocalString<1024> ls;
    NumericFormatter nf;

	details->AddItem({ "FTP Ifo", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Category);

     // -------------------------
    // General Connection Details
    // -------------------------
    details->AddItem({ "Connection ID", ls.Format("%-20s (%s)", "Not Parsed Yet", "0x00") })
        .SetType(ListViewItem::Type::Emphasized_1); // Highlighted Important Row

    details->AddItem({ "Client IP", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    details->AddItem({ "Server IP", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    AddDecAndHexElement("Client Port", "%-20s (%s)", 0); // Normal
    AddDecAndHexElement("Server Port", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Connection Type", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Highlighted);

    AddDecAndHexElement("Connection Duration (s)", "%-20s (%s)", 0); // Normal

    // -------------------------
    // Authentication Information
    // -------------------------
    details->AddItem({ "Username", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    details->AddItem({ "Password", "******" }) // Masked for security
        .SetType(ListViewItem::Type::GrayedOut);

    details->AddItem({ "Login Status", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Highlighted);

    AddDecAndHexElement("Login Attempts", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Last Login Time", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    // -------------------------
    // Session Details
    // -------------------------
    details->AddItem({ "Session Start Time", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Emphasized_2);

    details->AddItem({ "Session End Time", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Emphasized_2);

    AddDecAndHexElement("Total Commands Sent", "%-20s (%s)", 0); // Normal
    AddDecAndHexElement("Successful Commands", "%-20s (%s)", 0); // Normal
    AddDecAndHexElement("Failed Commands", "%-20s (%s)", 0); // Error Information

    // -------------------------
    // File Transfers (Downloads)
    // -------------------------
    details->AddItem({ "Downloaded Files", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Category);

    AddDecAndHexElement("Total Download Size (KB)", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Download Status", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::WarningInformation);

    AddDecAndHexElement("Download Speed (KB/s)", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Last Download Time", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    // -------------------------
    // File Transfers (Uploads)
    // -------------------------
    details->AddItem({ "Uploaded Files", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Category);

    AddDecAndHexElement("Total Upload Size (KB)", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Upload Status", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::WarningInformation);

    AddDecAndHexElement("Upload Speed (KB/s)", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Last Upload Time", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    // -------------------------
    // Security and Errors
    // -------------------------
    details->AddItem({ "Encryption Status", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Highlighted);

    details->AddItem({ "Security Protocol", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Normal);

    AddDecAndHexElement("Failed Auth Attempts", "%-20s (%s)", 0); // Error Information

    details->AddItem({ "Session Warnings", "No Warnings Detected" })
        .SetType(ListViewItem::Type::WarningInformation);

    details->AddItem({ "Session Errors", "No Errors Detected" })
        .SetType(ListViewItem::Type::ErrorInformation);

    // -------------------------
    // Advanced Stats
    // -------------------------
    AddDecAndHexElement("Bytes Sent", "%-20s (%s)", 0); // Normal
    AddDecAndHexElement("Bytes Received", "%-20s (%s)", 0); // Normal

    details->AddItem({ "Session Termination Reason", "Not Parsed Yet" })
        .SetType(ListViewItem::Type::Colored);
   }

// Adjust panel positions dynamically
void FtpDetails::RecomputePanelsPositions()
{
    CHECKRET(details.IsValid(), "");
    details->Resize(GetWidth(), std::min<>(this->GetHeight(), (int)details->GetItemsCount() + 3));
}

// Update method to refresh the panel
void FtpDetails::Update()
{
    details->DeleteAllItems();
    UpdateFtpDetailsInformation();
    RecomputePanelsPositions();
}