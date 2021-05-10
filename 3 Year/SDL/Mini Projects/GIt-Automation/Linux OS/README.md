# Git Project Initialization Automation (Linux OS)

## Command:

### For making `public repo`:
```bash
  $ python3 create.py -n <repo name>
   or
  $ python3 create.py --name <repo name> 
```   

### For making `private repo`:
```bash
  $ python3 create.py -n <repo name> -p
   or
  $ python3 create.py --name <repo name> --private 
```  

### Setup:
```bash
git clone https://github.com/mohitkhedkar/Git-Automation.git
cd Git-Automation/Linux\ OS/
pip3 install -r requirements.txt
    
touch .env 
add REPO PATH in create.py (ex:- /home/mohit/dev) "To get repo path  type <pwd> in terminal"
add 'Github' USERNAME in create.py
```
---
### .env setup: 
  after running `touch .env` command open the `.env` file and paste your github token.
```bash
 GITHUB_TOKEN=" "
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
 Copy the generated token and paste in `.env file`.




 ---
### Contibutors
1. [Megha Pal](https://github.com/meghapal02).
2. [Niraj Patil](https://github.com/niraj2347).
3. [Mohit Khedkar](https://github.com/mohitkhedkar).
