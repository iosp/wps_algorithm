#include <thread>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "algorithmsubsystem.h"
//#include <managementalgorithm_global.h>


AlgorithmSubSystem::AlgorithmSubSystem(ManagementAlgorithm* ma)
{
    std::cout<<"AlgorithmSubSystem has been constructed!"<<std::endl;
    m_mng_ptr = ma;
    //Building Status, Navigation Status, and more
    m_status=0x0;
}

AlgorithmSubSystem::AlgorithmSubSystem(const AlgorithmSubSystem &old_obj)
{
    m_mng_ptr=old_obj.m_mng_ptr;
}

int AlgorithmSubSystem::InitiateSensorLocationReporting(Region_Of_Mission rom, int frequency)
{
      /** This method is called by the WPS module when navigation sensor should be activated.
       *  After that, the module will start to report navigation data via ProcessSensorLocUpdate
       * according the frequency
       * ****/
    std::cout<<"AlgorithmSubSystem::InitiateSensorLocationReporting called with param:"<<rom<<std::endl;

    Calculated_Sensor_Geo_Loc_Orient geo_loc_orient=0;
    AlgNavigationNotificationTypes notification = AlgModuleStoppedLocationReporting;

    // According frequency
    m_mng_ptr->ProcessSensorLocUpdate(geo_loc_orient);
    return 0;

}

int AlgorithmSubSystem::StopSensorLocationReporting()
{
      /** This method is called by the WPS module to stop to report navigation data.
       *
       * ****/
    std::cout<<"AlgorithmSubSystem::StopSensorLocationReporting "<<std::endl;

    return 0;

}

int AlgorithmSubSystem::PrepareForModelConstruction(Region_Of_Mission rom, int required_model_quality, char** orthophoto, char** WPSModel)
{
      /** This method is called by the WPS module when building a model is needed.
       * - Check if already constructing model - if yes return 1
       *
       * In case the management module doesn't provide the updated models from the cloud,
       * then this method would require to:       *
       *    - Check if updated WPS model and orthophoto by querying last timestamp from the cloud
       * (queryCloud())
       * If needed:
       *    - Load orthophoto (RoM): m_mng_ptr->LoadOrthophoto(rom);
       *    - Load WPS Model  (RoM): m_mng_ptr->LoadWPSModel(rom);
        ***/
    std::cout<<"AlgorithmSubSystem::PrepareForModelConstruction called with param:"<<rom<<std::endl;

       /***
       * When algo is ready to build, notify management module
       * ****/
        AlgBuildingNotificationTypes notification = AlgModReadyForConstruction;
        m_mng_ptr->ProcessNotification(notification);

    return 0;
}

int AlgorithmSubSystem::UpdateSensorLocOrient(Platform_Location_Info loc_info)
{
      /** This method is called periodically by the WPS module to report location
       * of the platform so that the module will start building model when relevant.
       * This is used in conjunction with the picture captured by the camera
       *
       * When module starts to build model, it should activate the
       * stopSendingSensorLocationOrientation method
       *
       * ****/
    std::cout<<"AlgorithmSubSystem::UpdateSensorLocOrient called with param:"<<loc_info<<std::endl;

    return 0;

}

int AlgorithmSubSystem::StopModelConstruction()
{
      /** This method is called by the management platform in case of resources starvation
       * The Algo module should stop building the model
       *
       * ****/
    std::cout<<"AlgorithmSubSystem::StopModelConstruction "<<std::endl;
    AlgBuildingNotificationTypes notification = AlgModConstructionStopped;
    m_mng_ptr->ProcessNotification(notification);
    return 0;

}

void AlgorithmSubSystem::buildingModel()
{
    /***
     * This is one of the main method of the module Algo.
     * Each time a tile is ready, it alerts the management module.
     * ***/
    Tile this_tile=0;
    m_mng_ptr->UploadWPSData(this_tile);
}
