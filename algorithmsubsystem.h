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
    ManagementAlgorithm* m_mng_ptr;
    unsigned char m_status;
    void buildingModel();

public:
    AlgorithmSubSystem(){m_mng_ptr=(ManagementAlgorithm *)NULL;}
    AlgorithmSubSystem(ManagementAlgorithm *ma);
    AlgorithmSubSystem(const AlgorithmSubSystem &old_obj);
    int InitiateSensorLocationReporting(Region_Of_Mission rom, int frequency);
    int StopSensorLocationReporting();

    int PrepareForModelConstruction(Region_Of_Mission, int required_model_quality, char** orthophoto, char** WPSModel);
    int UpdateSensorLocOrient(Platform_Location_Info);
    int StopModelConstruction();
    unsigned char Status(){return m_status;}


    ManagementAlgorithm* myMng(){ if (m_mng_ptr != (ManagementAlgorithm *) NULL) return m_mng_ptr;
                                else return NULL;
                                }
    void setMngPointer(ManagementAlgorithm* mng_ptr){ if(m_mng_ptr == (ManagementAlgorithm *) NULL)
                                                    m_mng_ptr = mng_ptr; }

};

#endif // ALGORITHMSUBSYSTEM_H
