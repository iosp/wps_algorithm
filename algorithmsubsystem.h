#ifndef ALGORITHMSUBSYSTEM_H
#define ALGORITHMSUBSYSTEM_H

#pragma once
#include "algorithmsubsystem_global.h"
#include "wpstypes.h"
#include "../ManagementAlgorithm/managementalgorithm.h"

class ManagementAlgorithm;

class ALGORITHMSUBSYSTEMSHARED_EXPORT AlgorithmSubSystem
{
private:
    ManagementAlgorithm* m_alg_ptr;

public:
    AlgorithmSubSystem(ManagementAlgorithm *ma);
    AlgorithmSubSystem(const AlgorithmSubSystem &old_obj);
    int InitiateSensorLocationReporting(Region_Of_Mission rom);
    int StopSensorLocationReporting();

    int PrepareForModelConstruction(Region_Of_Mission, int required_model_quality);
    int UpdateSensorLocOrient(Platform_Location_Info);
    int StopModelConstruction();

    //bool Al_LoadOrthophoto(Region_Of_Mission);
   // bool Al_LoadWPSModel(Region_Of_Mission);
    //Al_ProcessNotification(AlgNotification);
    //int Al_ProcessSensorLocUpdate(Calculated_Sensor_Geo_Loc_Orient);
    //CloudQueryAnswer Al_QueryCloud(CloudQuery);
    //int stopUdatingLoc();
    int Al_StoreWPS_ModelData(CloudDataExchangeSpecification);
    int Al_UploadWPSData(CloudDataExchangeSpecification);

};

#endif // ALGORITHMSUBSYSTEM_H
