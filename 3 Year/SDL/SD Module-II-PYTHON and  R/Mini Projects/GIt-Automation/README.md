# Git Project Initialization Automation 

## Command:

### For making `public repo`:
```bash
  $ create.py -n <repo name>
   or
  $ create.py --name <repo name> 
```   

### For making `private repo`:
```bash
  $ create.py -n <repo name> -p
   or
  $ create.py --name <repo name> --private 
```   

### Git Commands we are Automating:
```bash
  $ git init
  $ touch README.md
  $ git add .
  $ git commit -m "Initial commit"
  $ git branch -M main
  $ git remote add origin <remote repo link>
  $ git push -u origin main
``` 

 ---
### Setup: 
Open the Command prompt
```bash
git clone https://github.com/mohitkhedkar/Git-Automation.git
cd Git-Automation
pip install -r requirements.txt
register.py
```
add `GITHUB TOKEN` , `GITHUB USERNAME` & `REPOPATH` in the Registration Window and `SUBMIT`

![](Screenshots/register.JPG)

### For running command from anywhere on system:
```bash
path:
  "Git-Automation" folder directory to path
```
---

### Getting the Github Token:

 Go to Github Settings -> Developer settings -> Personal access tokens -> Generate new token -> Note: `git automation`
 ##### Scopes required:
 - [x] repo  
    - [x] repo:status   
    - [x] repo_deployment
    - [x] repo:invite
    - [x] repo:invite
    - [x] security events 
 - [x] workflow 
 - [x] write:packages
    - [x] read:packages 
 - [x] delete:packages
 - [x] admin:org
    - [x] write:org
    - [x] read:org

 Click->`Generate Token`
 Copy the generated token and paste in `Registration Window`.
 
 ---
### Contibutors
1. [Megha Pal](https://github.com/meghapal02).
2. [Niraj Patil](https://github.com/niraj2347).
3. [Mohit Khedkar](https://github.com/mohitkhedkar).
