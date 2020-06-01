#include "periodvalues.h"

periodValues::periodValues(int numPeriods)
{
    setCode(0);
    for (int i = 0; i < numPeriods; i++) {
        flow.append(0);
        spill.append(0);
        temp.append(0);
        overGen.append(0);
        elevForebay.append(0);
        elevTailrace.append(0);
    }
}

int periodValues::getCode() const
{
    return code;
}

void periodValues::setCode(int value)
{
    code = value;
    if (abbv.isEmpty()) {
        switch(code)
        {
        case ANAT:// = 13334300, // Anatone,
            setAbbv("ANA");
            setName("Anatone");
            break;
                     // Anderson Ranch, Boise, ID 1950 40 MW
        case ARDB: // = 1831, // Arrow,
            setAbbv("ARDB");
            setName("Arrow");
            break;
                     // Big Cliff, Santiam, OR 1953 21 MW
                     // Black Canyon, Payette, ID 1925 10 MW
                     // Boise River Diversion, Boise, ID 1912 3 MW
        case BONN: // =  320, // Bonneville, Columbia, OR/WA 1938 1,225 MW
            setAbbv("BON");
            setName("Bonneville");
            break;
        case BLEE: // =  767, // Brownlee,
            setAbbv("BLE");
            setName("Brownlee");
            break;
        case BRIL: // = 1652, // Brilliant,
            setAbbv("BRIL");
            setName("Brilliant");
            break;
                     // Chandler, Yakima, WA 1956 12 MW
        case CHJO: // = 1270, // Chief Joseph, Columbia, WA 1958 2,614 MW
            setAbbv("CHJ");
            setName("Chief Joseph");
            break;
        case COLF: // = 1520, // Columbia Falls, , ,
            setAbbv("COLF");
            setName("Columbia Falls");
            break;
                     // Cougar, McKenzie, OR 1963 28 MW
                     // Detroit, Santiam, OR 1953 115 MW
                     // Dexter, Willamette, OR 1954 17 MW
        case DWOR: // =  535, // Dworshak, Clearwater, ID 1973 465 MW
            setAbbv("DWR");
            setName("Dworshak");
            break;
                     // Foster, Santiam, OR 1967 23 MW
        case GCOU: // = 1280, // Grand Coulee, Columbia, WA 1942 7,079 MW
            setAbbv("GCL");
            setName("Grand Coulee");
            break;
                     // Green Peter, Santiam, OR 1967 92 MW
                     // Green Springs, Emigrant Crk, OR 1960 17 MW
        case HELC: // =  762, // Hells Canyon, Snake,
            setAbbv("HCD");
            setName("Hells Canyon");
            break;
                     // Hills Creek, Willamette, OR 1962 34 MW
        case HHOR: // = 1530, // Hungry Horse, Flathead, MT 1953 428 MW
            setAbbv("HHOR");
            setName("Hungry Horse");
            break;
        case ICEH: // =  502, // Ice Harbor, Snake, WA 1962 693 MW
            setAbbv("IHR");
            setName("Ice Harbor");
            break;
        case JDAY: // =  440, // John Day, Columbia, OR/WA 1971 2,480 MW
            setAbbv("JDA");
            setName("John Day");
            break;
        case KERR: // = 1510, // Kerr,
            setAbbv("KERR");
            setName("Kerr");
            break;
        case LIBB: // = 1760, // Libby, Kootenai, MT 1975 605 MW
            setAbbv("LIBB");
            setName("Libby");
            break;
        case LGOO: // =  518, // Little Goose, Snake, WA 1970 930 MW
            setAbbv("LGS");
            setName("Little Goose");
            break;
        case LONG: // = 1305, // Long Lake,
            setAbbv("LONG");
            setName("Long Lake");
            break;
                     // Lookout Point, Willamette, OR 1953 138 MW
                     // Lost Creek, Rogue, OR 1977 56 MW
        case LGRA: // =  520, // Lower Granite, Snake, WA 1975 930 MW
            setAbbv("LWG");
            setName("Lower Granite");
            break;
        case LOMO: // =  504, // Lower Monumental, Snake, WA 1969 930 MW
            setAbbv("LMN");
            setName("Lower Monumental");
            break;
        case MCNR: // =  488, // McNary, Columbia, OR/WA 1952 1,120 MW
            setAbbv("MCN");
            setName("McNary");
            break;
                     // Minidoka, Snake, ID 1909 28 MW
                     // Palisades, Snake, ID 1958 177 MW
        case PECK: // = 13341050, // Peck,
            setAbbv("PEC");
            setName("Peck");
            break;
        case PRAP: // = 1160, // Priest Rapids, Columbia,
            setAbbv("PRD");
            setName("Priest Rapids");
            break;
        case RISL: // = 1170, // Rock Island, Columbia,
            setAbbv("RIS");
            setName("Rock Island");
            break;
        case RREA: // = 1200, // Rocky Reach, Columbia,
            setAbbv("RRH");
            setName("Rocky Reach");
            break;
                     // Roza, Yakima, WA 1958 13 MW
        case DALL: // =  365, // The Dalles, Columbia, OR/WA 1957 2,086 MW
            setAbbv("TDA");
            setName("The Dalles");
            break;
        case WANA: // = 1165, // Wanapum,
            setAbbv("WAN");
            setName("Wanapum");
            break;
        case WNTA: // = 1440, // Waneta,
            setAbbv("WNTA");
            setName("Waneta");
            break;
        case WELL: // = 1220  // Wells, Columbia,
            setAbbv("WEL");
            setName("Wells");
            break;

        default:
            setAbbv("");
            setName("");
        }
    }
}

QString periodValues::getName() const
{
    return name;
}

void periodValues::setName(const QString &value)
{
    name = value;
}

void periodValues::setName(int value)
{
    setCode(value);
}

QString periodValues::getAbbv() const
{
    return abbv;
}

void periodValues::setAbbv(const QString &value)
{
    abbv = value;
    if (code == 0) {
        if (abbv.contains("ANAT") || abbv.contains("ANA"))
            code = 13334300; // Anatone,
                     // Anderson Ranch, Boise, ID 1950 40 MW
        else if (abbv.contains("ARDB"))
            code = 1831; // Arrow,
                     // Big Cliff, Santiam, OR 1953 21 MW
                     // Black Canyon, Payette, ID 1925 10 MW
                     // Boise River Diversion, Boise, ID 1912 3 MW
        else if (abbv.contains("BON"))
            code =  320; // Bonneville, Columbia, OR/WA 1938 1,225 MW
        else if (abbv.contains("BLE"))
            code =  767; // Brownlee,
        else if (abbv.contains("BRIL"))
            code = 1652; // Brilliant,
                     // Chandler, Yakima, WA 1956 12 MW
        else if (abbv.contains("CHJ"))
            code = 1270; // Chief Joseph, Columbia, WA 1958 2,614 MW
        else if (abbv.contains("COLF"))
            code = 1520; // Columbia Falls, , ,
                     // Cougar, McKenzie, OR 1963 28 MW
                     // Detroit, Santiam, OR 1953 115 MW
                     // Dexter, Willamette, OR 1954 17 MW
        else if (abbv.contains("DWOR") || abbv.contains("DWR"))
            code =  535; // Dworshak, Clearwater, ID 1973 465 MW
                     // Foster, Santiam, OR 1967 23 MW
        else if (abbv.contains("GCOU") || abbv.contains("GCL"))
            code = 1280; // Grand Coulee, Columbia, WA 1942 7,079 MW
                     // Green Peter, Santiam, OR 1967 92 MW
                     // Green Springs, Emigrant Crk, OR 1960 17 MW
        else if (abbv.contains("HELC") || abbv.contains("HCD"))
            code =  762; // Hells Canyon, Snake,
                     // Hills Creek, Willamette, OR 1962 34 MW
        else if (abbv.contains("HHOR"))
            code = 1530; // Hungry Horse, Flathead, MT 1953 428 MW
        else if (abbv.contains("ICEH") || abbv.contains("IHR"))
            code =  502; // Ice Harbor, Snake, WA 1962 693 MW
        else if (abbv.contains("JDA"))
            code =  440; // John Day, Columbia, OR/WA 1971 2,480 MW
        else if (abbv.contains("KERR"))
            code = 1510; // Kerr,
        else if (abbv.contains("LIBB"))
            code = 1760; // Libby, Kootenai, MT 1975 605 MW
        else if (abbv.contains("LGOO") || abbv.contains("LGS"))
            code =  518; // Little Goose, Snake, WA 1970 930 MW
        else if (abbv.contains("LONG"))
            code = 1305; // Long Lake,
                     // Lookout Point, Willamette, OR 1953 138 MW
                     // Lost Creek, Rogue, OR 1977 56 MW
        else if (abbv.contains("LGRA") || abbv.contains("LWG"))
            code =  520; // Lower Granite, Snake, WA 1975 930 MW
        else if (abbv.contains("LOMO") || abbv.contains("LMN"))
            code =  504; // Lower Monumental, Snake, WA 1969 930 MW
        else if (abbv.contains("MCN"))
            code =  488; // McNary, Columbia, OR/WA 1952 1,120 MW
                     // Minidoka, Snake, ID 1909 28 MW
                     // Palisades, Snake, ID 1958 177 MW
        else if (abbv.contains("PECK"))
            code = 13341050; // Peck,
        else if (abbv.contains("PRAP") || abbv.contains("PRD"))
            code = 1160; // Priest Rapids, Columbia,
        else if (abbv.contains("RIS"))
            code = 1170; // Rock Island, Columbia,
        else if (abbv.contains("RREA") || abbv.contains("RRH"))
            code = 1200; // Rocky Reach, Columbia,
                     // Roza, Yakima, WA 1958 13 MW
        else if (abbv.contains("DALL") || abbv.contains("TDA"))
            code =  365; // The Dalles, Columbia, OR/WA 1957 2,086 MW
        else if (abbv.contains("WAN"))
            code = 1165; // Wanapum,
        else if (abbv.contains("WNTA"))
            code = 1440; // Waneta,
        else if (abbv.contains("WEL"))
            code = 1220;  // Wells, Columbia,
        else
            code = 0;
    }
}

void periodValues::setAbbv(int value)
{
    setCode(value);
}

float periodValues::getFlow(int index) const
{
    return flow[index];
}

void periodValues::setFlow(int index, const float &value)
{
    flow[index] = value;
}
