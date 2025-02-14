#include <iostream>
#include <string>

using namespace std;

class FitnessTracker {
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int stepGoal) {
        userName = name;
        dailyStepGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps) {
        stepsTaken += steps;
        caloriesBurned += steps * 0.04;
        cout << userName << " has walked " << steps << " steps today." << endl;
    }

    double calculateCaloriesBurned() {
        return caloriesBurned;
    }

    void checkProgress() {
        cout << userName << "'s progress for the day:" << endl;
        cout << "Steps Taken: " << stepsTaken << " out of " << dailyStepGoal << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;

        if (stepsTaken >= dailyStepGoal) {
            cout << "Great job! You've met your step goal for the day." << endl;
        } else {
            cout << "Keep going! You haven't met your step goal yet." << endl;
        }
    }

    bool isGoalMet() {
        return stepsTaken >= dailyStepGoal;
    }
};

int main() {
    FitnessTracker laibaTracker("Laiba", 10000);

    laibaTracker.logSteps(2500); 
    laibaTracker.logSteps(4000); 
    laibaTracker.logSteps(3000); 

    laibaTracker.checkProgress();

    cout << "Total Calories Burned: " << laibaTracker.calculateCaloriesBurned() << " kcal" << endl;

    if (laibaTracker.isGoalMet()) {
        cout << "Laiba has met her daily goal!" << endl;
    } else {
        cout << "Laiba has not met her daily goal yet." << endl;
    }

    return 0;
}
