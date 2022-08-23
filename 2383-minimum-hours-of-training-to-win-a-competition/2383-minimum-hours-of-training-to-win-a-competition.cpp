class Solution {
public:
int minNumberOfHours(int energy, int experience, vector<int>& energies, vector<int>& experiences) {
        int training = 0;
        for (int i = 0; i < size(energies); ++i) {
            // Energy.
            if (energy <= energies[i]) {
                // How much more training hours do we need to be 1 higher?
                training += energies[i] + 1 - energy;
                energy = energies[i] + 1;
            }
            energy -= energies[i];
            
            // Experience.
            if (experience <= experiences[i]) {
                // Same here.
                training += experiences[i] + 1 - experience;
                experience = experiences[i] + 1;
            }
            experience += experiences[i];
        }
        return training;
    }
};