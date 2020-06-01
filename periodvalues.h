#ifndef PERIODVALUES_H
#define PERIODVALUES_H

#include <QVector>
#include <QString>

class periodValues
{
public:
    periodValues(int numPeriods);

    int getCode() const;
    void setCode(int value);

    QString getName() const;
    void setName(const QString &value);
    void setName(int value);

    QString getAbbv() const;
    void setAbbv(const QString &value);
    void setAbbv(int value);

    float getFlow(int index) const;
    void setFlow(int index, const float &value);

private:
    int code;
    QString name;
    QString abbv;
    QVector<float> flow;
    QVector<float> spill;
    QVector<float> spillPct;
    QVector<float> overGen;
    QVector<float> temp;
    QVector<float> elevForebay;
    QVector<float> elevTailrace;
};


enum codeBPA {
    //Abv = num, // Name, River, State, Year, Power
                 // Albeni Falls, Pend Oreille, ID 1955 49 MW
    ANAT = 13334300, // Anatone,
                 // Anderson Ranch, Boise, ID 1950 40 MW
    ARDB = 1831, // Arrow,
                 // Big Cliff, Santiam, OR 1953 21 MW
                 // Black Canyon, Payette, ID 1925 10 MW
                 // Boise River Diversion, Boise, ID 1912 3 MW
    BONN =  320, // Bonneville, Columbia, OR/WA 1938 1,225 MW
    BLEE =  767, // Brownlee,
    BRIL = 1652, // Brilliant,
                 // Chandler, Yakima, WA 1956 12 MW
    CHJO = 1270, // Chief Joseph, Columbia, WA 1958 2,614 MW
    COLF = 1520, // Columbia Falls, , ,
                 // Cougar, McKenzie, OR 1963 28 MW
                 // Detroit, Santiam, OR 1953 115 MW
                 // Dexter, Willamette, OR 1954 17 MW
    DWOR =  535, // Dworshak, Clearwater, ID 1973 465 MW
                 // Foster, Santiam, OR 1967 23 MW
    GCOU = 1280, // Grand Coulee, Columbia, WA 1942 7,079 MW
                 // Green Peter, Santiam, OR 1967 92 MW
                 // Green Springs, Emigrant Crk, OR 1960 17 MW
    HELC =  762, // Hells Canyon, Snake,
                 // Hills Creek, Willamette, OR 1962 34 MW
    HHOR = 1530, // Hungry Horse, Flathead, MT 1953 428 MW
    ICEH =  502, // Ice Harbor, Snake, WA 1962 693 MW
    JDAY =  440, // John Day, Columbia, OR/WA 1971 2,480 MW
    KERR = 1510, // Kerr,
    LIBB = 1760, // Libby, Kootenai, MT 1975 605 MW
    LGOO =  518, // Little Goose, Snake, WA 1970 930 MW
    LONG = 1305, // Long Lake,
                 // Lookout Point, Willamette, OR 1953 138 MW
                 // Lost Creek, Rogue, OR 1977 56 MW
    LGRA =  520, // Lower Granite, Snake, WA 1975 930 MW
    LOMO =  504, // Lower Monumental, Snake, WA 1969 930 MW
    MCNR =  488, // McNary, Columbia, OR/WA 1952 1,120 MW
                 // Minidoka, Snake, ID 1909 28 MW
                 // Palisades, Snake, ID 1958 177 MW
    PECK = 13341050, // Peck,
    PRAP = 1160, // Priest Rapids, Columbia,
    RISL = 1170, // Rock Island, Columbia,
    RREA = 1200, // Rocky Reach, Columbia,
                 // Roza, Yakima, WA 1958 13 MW
    DALL =  365, // The Dalles, Columbia, OR/WA 1957 2,086 MW
    WANA = 1165, // Wanapum,
    WNTA = 1440, // Waneta,
    WELL = 1220  // Wells, Columbia,
};

enum codeCOMPASS {
    ANA = 13334300, // Anatone, USCOE
    PEC = 13341050, // Peck, USCOE
    BON =  320, // Bonneville, Columbia, OR/WA 1938 1,225 MW,
    TDA =  365, // The Dalles, Columbia, OR/WA 1957 2,086 MW
    JDA =  440, // John Day, Columbia, OR/WA 1971 2,480 MW,
    PRD = 1160, // Priest Rapids, Columbia,
    RIS = 1170, // Rock Island, Columbia,
    RRH = 1200, // Rocky Reach, Columbia,
    MCN =  488, // McNary, Columbia, OR/WA 1952 1,120 MW
    WAN = 1165, // Wanapum,
    WEL = 1220, // Wells, Columbia,
    CHJ = 1270, // Chief Joseph, Columbia, WA 1958 2,614 MW
    GCL = 1280, // Grand Coulee, Columbia, WA 1942 7,079 MW
    DWR =  535, // Dworshak, Clearwater, ID 1973 465 MW
    LWG =  520, // Lower Granite, Snake, WA 1975 930 MW
    LMN =  504, // Lower Monumental, Snake, WA 1969 930 MW
    IHR =  502, // Ice Harbor, Snake, WA 1962 693 MW
    LGS =  518, // Little Goose, Snake, WA 1970 930 MW
    HCD =  762, // Hells Canyon, Snake
    BLE =  767  // Brownlee, Snake
};


#endif // PERIODVALUES_H
