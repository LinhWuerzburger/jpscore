/**
 * \section License
 * This file is part of JuPedSim.
 *
 * JuPedSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * JuPedSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with JuPedSim. If not, see <http://www.gnu.org/licenses/>.
 **/
//
// Created by laemmel on 24.03.16.
//

#ifndef JPSCORE_INIFILEPARSER_H
#define JPSCORE_INIFILEPARSER_H

#include <string>

#include "../general/Configuration.h"
#include "../routing/DirectionStrategy.h"

class OutputHandler;

class TiXmlElement;

class TiXmlNode;

extern OutputHandler* Log;

class IniFileParser {

public:
     IniFileParser(Configuration* config);

     bool Parse(std::string iniFile);

private:
     bool ParseGCFMModel(TiXmlElement* xGCFM);

     bool ParseGompertzModel(TiXmlElement* xGompertz);

     bool ParseGradientModel(TiXmlElement* xGradient);

     bool ParseVelocityModel(TiXmlElement* xVelocity);

     void ParseAgentParameters(TiXmlElement* operativModel);

     bool ParseRoutingStrategies(TiXmlNode* routingNode);

     bool ParseCogMapOpts(TiXmlNode* routingNode);

     bool ParseLinkedCells(const TiXmlNode& linkedCellNode);

     bool ParseStepSize(TiXmlNode& stepNode);

     bool ParsePeriodic(TiXmlNode& Node);

     bool ParseNodeToSolver(const TiXmlNode& solverNode);

     bool ParseStrategyNodeToObject(const TiXmlNode& strategyNode);

     Configuration* _config;
     int _model;
     std::shared_ptr<DirectionStrategy> _exit_strategy;

};

#endif //JPSCORE_INIFILEPARSER_H