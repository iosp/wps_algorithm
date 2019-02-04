#ifndef WPSTYPES_H
#define WPSTYPES_H
#pragma once
typedef int Region_Of_Mission;
typedef int Tile;
typedef int Platform_Location_Info;
typedef int CloudQueryAnswer;
typedef int CloudQuery;
typedef int Calculated_Sensor_Geo_Loc_Orient;
typedef long DateAndTime;

enum AlgBuildingNotificationTypes {
    AlgModInit=0,
    AlgModReadyForConstruction=1,
    AlgModBuilding,
    AlgModConstructionComplete,
    AlgModConstructionStopped,
    AlgModPrepareForConstruction
};

enum AlgNavigationNotificationTypes {
    AlgModuleStoppedLocationReporting=0,
    AlgModuleLocationReporting
};

enum MgmNotificationTypes {
    MM_FinishedDownloadingCloudModel,
    MM_FinishedDownloadingOrthoPhoto,
};



#endif // WPSTYPES_H
