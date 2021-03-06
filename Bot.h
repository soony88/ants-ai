#ifndef BOT_H_
#define BOT_H_

#include "State.h"

/*
    This struct represents your bot in the game of Ants
*/
struct Bot
{
    // Attributes
    State state;
    std::vector<Ant*> myAnts;

    std::vector<Ant*> dangeredAnts;
    std::vector<std::vector<bool> > enemyHillsGrid;
    std::vector<Location> enemyHills;

    std::vector<Ant*> conscriptedAnts;

    // Constructor
    Bot();

    // Methods
    void playGame();    //plays a single game of Ants
    void makeMoves();   //makes moves for a single turn
    void endTurn();     //indicates to the engine that it has made its moves

    // Initialise Turn
    void SpawnNewAnts();
    void DeleteDeadAnts();
    void PlaceAntsInSquares();
    void ResetAnts();
    void NearbyAllies();
    void NearbyEnemies();
    void ClearDangerZones();
    void EnemyHills();

    // Defence
    void Defence();
    void GuardBase(Location h);
    void UltimateGuardBase(Location h);
    bool BaseInDanger(Location h, double maxDist);

    // Explore
    void MoveToHighVal(Ant* ant);
    void MoveToLowVal(Ant* ant);
    void UpdateGridValues();
    void ReduceValue(int row, int col);

    // BFS
    void SearchRadius(std::vector<Location> locations, Mission mission);

    // A*
    void AStar(Ant* ant, Location dest, Mission mission);
    int IndNodeSmallestF(std::deque<Node> queue);

    double FindPathDist(Location origin, Location dest);

    // Offence
    void AttackHills();
    void AttackAnts();

    // Other
    void CheckPath(Ant* ant, int* dir, Location* loc);
};

#endif //BOT_H_
