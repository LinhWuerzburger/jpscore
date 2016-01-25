#include "locater.h"
#include "../cognitiveMap/cognitivemap.h"
#include "../../../pedestrian/Pedestrian.h"

Locater::Locater(const Building *b, const double &updateInterval): AbstractSensor(b)
{
    _updateInterval=updateInterval;
}

Locater::~Locater()
{

}

std::string Locater::GetName() const
{
    return "Locater";
}

void Locater::execute(const Pedestrian * ped, CognitiveMap * cogMap) const
{
   //Log->Write("INFO:\t Update Pointer");
   cogMap->UpdateDirection();

   //std::cout << std::to_string(ped->GetGlobalTime()) << std::endl;
   cogMap->UpdateYAHPointer(ped->GetV()*_updateInterval);

   cogMap->WriteToFile();

}
