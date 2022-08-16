struct Node
{

    std::vector<StreetSegmentIdx> outgoing_edges;
    StreetSegmentIdx reachingEdge;
    double bestTime = 99999;
};

double estTimeRemaining(IntersectionIdx srcID, IntersectionIdx destID);

bool bfsPath(int srcID, int destID, const double turn_penalty);
std::vector<StreetSegmentIdx> bfsTraceBack(int destID);
std::vector<Node> nodes;

double computePathTravelTime(const double turn_penalty, const std::vector<StreetSegmentIdx>& path){
        double netTime = 0;    
        double lastSegTime;
        StreetSegmentInfo lastSegStruct = getStreetSegmentInfo(path[path.size()-1]);
        double lastSpeedLim = lastSegStruct.speedLimit;
        double lastSegLength = findStreetSegmentLength(path[path.size()-1]);
         lastSegTime = lastSegLength/lastSpeedLim;
         
    for(auto i = 0; i < path.size() - 1 ; i++){
        
        //Pseudo : TRAVELTime definition: Sum of Street segment lengths/(speed limit + turn penalties)
        //for the vector of street segment ID's that the path contatins
                // compute the sum of all the distances within the path;: to do this:
                // for the street segment in the path, get its distance between that and the next segment.
                // if the street ID for that Streetsegment 

                //
        StreetSegmentInfo currSegStruct = getStreetSegmentInfo(path[i]); 
        StreetSegmentInfo nextSegStruct = getStreetSegmentInfo(path[i+1]); //place an if-statement to make sure element being passed is greater than size one
        // for the streetSegId, get a struct with its info such as its speed limit.
        double speedLim = currSegStruct.speedLimit;
        double currSegLength = findStreetSegmentLength(path[i]);
        
        if(currSegStruct.streetID != nextSegStruct.streetID){ 
            netTime += (double(currSegLength))/(double(speedLim)) + (double(turn_penalty)); 
        }
        else{
            netTime += (double(currSegLength))/(double(speedLim));           
        }
  
    }
   // std::cout <<netTime + lastSegTime << std::endl;
    return (netTime + lastSegTime);
}

std::vector<StreetSegmentIdx> findPathBetweenIntersections(
                  const double turn_penalty,
                  const std::pair<IntersectionIdx, IntersectionIdx> intersect_ids){
    
    std::vector<StreetSegmentIdx> path;
    
    
    bool path_exist = bfsPath(intersect_ids.first, intersect_ids.second, turn_penalty);
    
    if (path_exist){
        
        path = bfsTraceBack(intersect_ids.second);
    }
    
    return path;
}

bool bfsPath(int srcID, int destID, const double turn_penalty){
    
    nodes.clear();
    nodes.resize(getNumIntersections());
    auto cmp = [](WaveElem left, WaveElem right) { return (left.travelTime + left.estTime) > (right.travelTime + right.estTime); };
    std::priority_queue<WaveElem, std::vector<WaveElem>, decltype(cmp)> wavefront(cmp);

    wavefront.push(WaveElem(srcID, NO_EDGE, 0, 0));

    while (wavefront.size() != 0){
        
        WaveElem curr = wavefront.top();
        wavefront.pop();
        
        nodes[curr.nodeID].outgoing_edges = findStreetSegmentsOfIntersection(curr.nodeID);
        
        if (curr.travelTime < nodes[curr.nodeID].bestTime){
            
            nodes[curr.nodeID].reachingEdge = curr.edgeID;
            nodes[curr.nodeID].bestTime = curr.travelTime;

            if (curr.nodeID == destID){
                return true;
            }

            std::vector<StreetSegmentIdx> edge_list = nodes[curr.nodeID].outgoing_edges;
            StreetSegmentInfo out_ss_info;
            StreetSegmentInfo in_ss_info;
            
            if (nodes[curr.nodeID].reachingEdge != NO_EDGE){
                
              in_ss_info = getStreetSegmentInfo(nodes[curr.nodeID].reachingEdge);
            }
           
            IntersectionIdx toNodeID;

            for (int i = 0; i < edge_list.size(); i++){

                out_ss_info = getStreetSegmentInfo(edge_list[i]);
                
                
                if (curr.nodeID == out_ss_info.to && out_ss_info.oneWay == true){

                    continue;
                }
                else if (curr.nodeID == out_ss_info.from){
                    
                    toNodeID = out_ss_info.to;
                }
                else{
                    
                    toNodeID = out_ss_info.from;
                }
                
                double time = findStreetSegmentTravelTime(edge_list[i]);
                double estTime = estTimeRemaining(toNodeID, destID);

                if (nodes[curr.nodeID].reachingEdge != NO_EDGE && (in_ss_info.streetID != out_ss_info.streetID)){ //this assumes that there is always a turn penalty at the beginning...

                    time = time + turn_penalty;
                }
                
                wavefront.push(WaveElem(toNodeID, edge_list[i], nodes[curr.nodeID].bestTime + time, estTime));
                 
            }           
            
        }
                
    }
    
    return false;
}

std::vector<StreetSegmentIdx> bfsTraceBack(IntersectionIdx destID){
    
    std::list<StreetSegmentIdx> path;
    
    IntersectionIdx currNodeID = destID;
    StreetSegmentIdx prevEdge = nodes[currNodeID].reachingEdge;
    
    while (prevEdge != NO_EDGE){
        
        StreetSegmentInfo ss_info = getStreetSegmentInfo(prevEdge);
        
        path.push_front(prevEdge);
        
        if (ss_info.to == currNodeID){
            
            currNodeID = ss_info.from;
        }
        else{
            
            currNodeID = ss_info.to;
        }
        
        prevEdge = nodes[currNodeID].reachingEdge;
    }
    
    std::vector<StreetSegmentIdx> path_vec;
    for (StreetSegmentIdx const &n : path){
        
        path_vec.push_back(n);
    }
   
    //std::vector<StreetSegmentIdx> path_vec{ std::make_move_iterator(std::begin(path)), 
                  //::make_move_iterator(std::end(path)) };
                  
    return path_vec;
}

double estTimeRemaining(IntersectionIdx srcID, IntersectionIdx destID){
    
    double speedLim;
    double distance;
    double estTime;
    
    if (map.compare("Beijing") == 0)
    {
        speedLim = 27.7778; //100
    }
    else if (map.compare("Tehran") == 0)
    {
        speedLim = 33.3333; //120
    }
    else if (map.compare("New Delhi") == 0)
    {
        speedLim = 33.3333; //120
    }
    else if (map.compare("Cairo") == 0)
    {
       speedLim = 33.3333; //120
    }
    else if (map.compare("New York") == 0)
    {
        speedLim = 29.1667; //105
    }
    else if (map.compare("Tokyo") == 0)
    {
        speedLim = 33.3333; //120
    }
    else if (map.compare("Cape Town") == 0)
    {
        speedLim = 33.3333; //120
    }
    else if (map.compare("Golden Horseshoe") == 0)
    {
        speedLim = 27.7778; //100
    }
    else if (map.compare("Hamilton") == 0)
    {
        speedLim = 27.7778; //100
    }
    else if (map.compare("Hong Kong") == 0)
    {
        speedLim = 27.7778; //100
    }
    else if (map.compare("Iceland") == 0)
    {
        speedLim = 27.7778; //100
    }
    else if (map.compare("Interlaken") == 0)
    {
        speedLim = 33.3333; //120
    }
    else if (map.compare("London") == 0)
    {
        speedLim = 33.3333; //115 -> 120
    }
    else if (map.compare("Moscow") == 0)
    {
        speedLim = 36.1111; //130
    }
    else if (map.compare("Rio De Janeiro") == 0)
    {
        speedLim = 30.5556; //110
    }
    else if (map.compare("Saint Helena") == 0)
    {
        speedLim = 13.8889; //50
    }
    else if (map.compare("Singapore") == 0)
    {
        speedLim = 25; //90
    }
    else if (map.compare("Sydney") == 0)
    {
        speedLim = 30.5556; //110
    }
    
    std::pair<LatLon, LatLon> positions (getIntersectionPosition(srcID), getIntersectionPosition(destID));
    
    distance = findDistanceBetweenTwoPoints(positions);
    
    estTime = distance / speedLim;
    
    return estTime;
    
}
