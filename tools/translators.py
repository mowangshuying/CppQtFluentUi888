import os

# set project dir
projectDir="E:\CodeLibraries\GithubLibraries\CppQtFluentUi888"
def isFluDir(fileName):
    if fileName.find("Flu") == 0:
        return True
    return False

def isHS(fileName):
    if fileName.find(".h") != -1 or fileName.find(".cpp") != -1:
        return True
    return False

def isMD(filename):
    if filename.find(".md") != -1:
        return True
    return False

def getFluDir():
    fluDir = []
    for item in os.listdir(projectDir): 
        if isFluDir(item):
            path = os.path.join(projectDir, item)
            fluDir.append(path)
            
    return fluDir

def getFluHS(dir):
    fluHS = []
    for item in os.listdir(dir):
        if isHS(item):
            path = os.path.join(dir, item)
            fluHS.append(path)
    return fluHS

def translatorsHS():
    HS = []
    FluDir = getFluDir()
    
    for item in FluDir:
        hs = getFluHS(item)
        for hsItem in hs:
            HS.append(hsItem)
            
    # slove qss
    for item in HS:
        fileData = ""
        with open(item, "r", encoding="utf-8") as f:
            for line in f:
                if "../StyleSheet/light" in line:
                    line = line.replace("../StyleSheet/light", ":/StyleSheet/light")
                elif "../StyleSheet/dark" in line:
                    line = line.replace("../StyleSheet/dark", ":/StyleSheet/dark")
                elif "../res/" in line:
                    line = line.replace("../res/", ":/res/")
                elif "../code/" in line:
                    line = line.replace("../code/", ":/code/")
                fileData += line
        
        with open(item, "w", encoding="utf-8")  as f:
            f.write(fileData)
            
            
def translatorsCode():
    C = []
    CP = os.path.join(projectDir, "code")
    
    for item in os.listdir(CP):
        if isMD(item):
            path = os.path.join(CP, item)
            C.append(path)
    
    for item in C:
        fileData = ""
        with open(item, "r", encoding="utf-8") as f:
            for line in f:
                if "../StyleSheet/light" in line:
                    line = line.replace("../StyleSheet/light", ":/StyleSheet/light")
                elif "../StyleSheet/dark" in line:
                    line = line.replace("../StyleSheet/dark", ":/StyleSheet/dark")
                elif "../res/" in line:
                    line = line.replace("../res/", ":/res/")
                elif "../code/" in line:
                    line = line.replace("../code/", ":/code/")
                fileData += line
        
        with open(item, "w", encoding="utf-8")  as f:
            f.write(fileData)
    
    
        
    
if __name__ == '__main__':
    translatorsHS()
    translatorsCode()
    
