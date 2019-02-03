#include <thread>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "algorithmsubsystem.h"
//#include <managementalgorithm_global.h>


AlgorithmSubSystem::AlgorithmSubSystem(ManagementAlgorithm* ma)
{
    m_alg_ptr = ma;
}

AlgorithmSubSystem::AlgorithmSubSystem(const AlgorithmSubSystem &old_obj)
{
    m_alg_ptr=old_obj.m_alg_ptr;
}

int AlgorithmSubSystem::InitiateSensorLocationReporting(Region_Of_Mission rom)
{
      /** This method is called by the WPS module when navigation sensor should be activated.
       *  After that, the module will start to report navigation data via ProcessSensorLocUpdate
       * ****/
    std::cout<<"AlgorithmSubSystem::InitiateSensorLocationReporting called with param:"<<rom<<std::endl;

    Calculated_Sensor_Geo_Loc_Orient geo_loc_orient;
    m_alg_ptr->ProcessSensorLocUpdate(geo_loc_orient);
    return 1;

}

int AlgorithmSubSystem::StopSensorLocationReporting()
{
      /** This method is called by the WPS module to stop to report navigation data.
       *
       * ****/
    return 1;

}

int AlgorithmSubSystem::PrepareForModelConstruction(Region_Of_Mission rom, int required_model_quality)
{
      /** This method is called by the WPS module when building a model is needed.
       * This method should require to:
       *    - Check if already constructing model
       *    - Check if updated orthophoto needed
       *    - Check if updated WPS model by querying last timestamp from the cloud
       * (queryCloud())
       * If needed:
       *    - Load orthophoto (RoM)
        ***/
    std::cout<<"AlgorithmSubSystem::PrepareForModelConstruction called with param:"<<rom<<std::endl;

       int ret;
       ret = m_alg_ptr->LoadOrthophoto(rom);
       /**
       *    - Load WPS Model  (RoM)
       * **/
       ret = m_alg_ptr->LoadWPSModel(rom);
       /***
       * When module is ready, send notification via processNotification
       * ****/
        AlgNotificationTypes notification = AlgModReadyForConstruction;
        m_alg_ptr->ProcessNotification(notification);

    return 1;
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

    return 1;

}

int AlgorithmSubSystem::StopModelConstruction()
{
      /** This method is called by the management platform in case of resources starvation
       * The Algo module should stop building the model
       *
       * ****/
    return 1;

}

