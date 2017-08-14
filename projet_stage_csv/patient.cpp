#include "patient.h"

using namespace std;
using namespace boost::gregorian;

CTScanAppointment::CTScanAppointment()
{

}

string CTScanAppointment::to_string()
{
    string str;
    str = CTScan::to_string();
    str += " ";
    str += std::to_string(days_since_first_scan);
    return str;
}

string CTScanAppointment::gnuplot_formated_data()
{
    string str;
    str += std::to_string(days_since_first_scan);
    str += " ";
    str += CTScan::Result_of_scan();
    return str;
}

CTScanAppointment CTScanAppointment::from_ctscan(CTScan ctscan)
{
    CTScanAppointment b;
    b.DCT = ctscan.DCT;
    b.DSOL = ctscan.DSOL;
    b.ct_density = ctscan.ct_density;
    b.sol_density = ctscan.sol_density;
    b.date = ctscan.date;
    b.sdate = ctscan.sdate;
    return b;
}

Patient::Patient()
{

}

std::vector<CTScanAppointment> Patient::get_appointments()
{
    std::vector<CTScanAppointment> datafromappointment;
    if(scans.size() == 0) { return datafromappointment; }
    date first_scan = scans[0].date;
    for(CTScan scan : scans)
    {
        CTScanAppointment b = CTScanAppointment::from_ctscan(scan);
        b.days_since_first_scan = (b.date - first_scan).days();
        datafromappointment.push_back(b);
    }
    return datafromappointment;
}

string Patient::to_string()
{
    string str;
    str += "ID : ";
    str += std::to_string(id);
    str += " | age : ";
    str += std::to_string(age);
    str += " | sexe :";
    str += genre;
    str += "\n Mutation : \n";
    str += "EGFR mutation : ";
    str += EGFRmutation;
    str += "\n";
    str += "KRAS mutation : ";
    str += KRASmutation;
    str += "\n";
    str += "ALK mutation : ";
    str += ALKmutation;
    str += "\n CTscans : \n";
    for(CTScan scan : scans)
    {
        str += "\n";
        str += "[";
        str += scan.to_string();
        str += "] ";
    }

    return str;
}
