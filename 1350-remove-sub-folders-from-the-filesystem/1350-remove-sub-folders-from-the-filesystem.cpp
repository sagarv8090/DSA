class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        string lastAddedFolder;
        
        for (const string& f : folder) {
            // If the current folder does not start with the last added folder + "/",
            // then it's not a sub-folder of the last added folder.
            if (lastAddedFolder.empty() || f.find(lastAddedFolder + "/") != 0) {
                result.push_back(f);
                lastAddedFolder = f;  // Update the last added folder
            }
        }
        
        return result;
    }
};
