#ifndef WPSTYPES_H
#define WPSTYPES_H
#pragma once
typedef int Region_Of_Mission;
typedef int CloudDataExchangeSpecification;
typedef int Platform_Location_Info;
typedef int CloudQueryAnswer;
typedef int CloudQuery;
typedef int Calculated_Sensor_Geo_Loc_Orient;
enum AlgNotificationTypes {
    AlgNull=0,
    AlgModReadyForConstruction=1,
    AlgModStartedForConstruction,
    AlgModConstructionComplete,
    MM_FinishedDownloadingCloudModel,
    MM_FinishedDownloadingOrthoPhoto,
    AlgModuleStoppedLocationReporting

};

#endif // WPSTYPES_H
