# A small project to practice git 
In this exercise, you’ll work with a Python script (main.py), uncomment sections step-by-step by removing "#" before the line, commit changes, and run the script to see the output. The project runs in GitHub Codespaces and focuses on Git essentials with immediate feedback.

As there are several files, you can work in groupe (2 personnes) to achieve the efficiency. 
## 0. Initial Setup
Before diving into Git operations, configure your Git environment in Codespaces.
### SSH Key configuration
- In the Codespaces terminal:
  ```bash
  ssh-keygen -t ed25519 -C "your.email@example.com"
  ```
- Press Enter for default file (~/.ssh/id_ed25519), skip passphrase (press Enter twice).
- Add your SSH key to the ssh-agent
    ```bash 
    eval "$(ssh-agent -s)"
    ```
- Add SSH private key to the ssh-agent
    ```bash 
    ssh-add ~/.ssh/id_ed25519
    ```
- Copy the public key
     ```bash 
     cat ~/.ssh/id_ed25519.pub
    ```
- Add SSH Key to GitHub
    - Go to Settings > SSH and GPG keys > New SSH key.
    - Paste the key from the previous step.
    - Set title: “Class Key”.
    - Click Add SSH key.
- Test the connection:
     ```bash 
    ssh -T git@github.com
    ```
### Local configurations
- Add your name and your email
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
- Set VS Code as the default editor:
```bash
git config --global core.editor "code --wait"
```
> The ```--wait``` flag ensures Git waits for VS Code to close before proceeding.
- Configure difftool to use VS Code
```bash
git config --global diff.tool vscode
git config --global difftool.vscode.cmd "code --wait --diff \$LOCAL \$REMOTE"
```
- Configure mergetool to use VS Code
```bash
git config --global merge.tool vscode
git config --global mergetool.vscode.cmd "code --wait --merge \$REMOTE \$LOCAL \$BASE \$MERGED"
```
- Add useful Git aliases
```bash
git config --global alias.st status
git config --global alias.ci commit
git config --global alias.br branch
git config --global alias.loggraph ‘log --all --decorate --oneline --graph’
git config --global alias.log1 ‘log --oneline’
```
> These shorten ```git status``` to ```git st```, ```git commit``` to ```git ci```,```git branch``` to ```git br``` and so on.
- Verify your settings
```bash
git config --global --list
```
## 1. Fork the project
You do not have write permission on this project, you will hence need to fork it. Of course, since ***Dev.A*** and ***Dev.B*** will be collaborating to the same project, only one of them should create the fork for the group.

***Dev.B***: Fork the project by clicking on the fork button in the upper right corner of the project page.

Now ***Dev.B*** has his own copy of the project. In order to give ***Dev.A*** write permissions to the project,
***Dev.B*** needs to add ***Dev.A*** to the project’s list of collaborators: *Settings -> Collaborators*.

## 2. Clone the repository
Both ***Dev.A*** and ***Dev.B*** clone it and then go to the local repository 
```
cd GitTP
```
Both open gitk to visualize the workflow
```
gitk --all &
```
gitk should be updated after each git command to check the changes.
## 3. Commit and push
In this part, ***Dev.B*** does the same thing as ***Dev.A***, but in *Step 2*
1. ***Dev.A*** delete "/*" and "*/" in *Step 1* in file *main.cpp*, check the change with 
```
git statut
```
2. ***Dev.A*** stage the modifications (check gitk)
```
git add main.cpp
```
3. ***Dev.A*** commit this modifications 
```
git commit -m "uncomment Step 1"
```
check gitk

4. ***Dev.A*** push this commit
```
git push
```
> One of the teammate will find that it is not possible to push the modifications. Try to figure it out. 

> Tips: The teammate push after the first need to do ```git pull``` before the ```git push```

5. Try to get the same output for gitk when finished. 

## 4. Branch and merge
In this part, ***Dev.B*** does the same thing as ***Dev.A***, but in *Step 4*
1. ***Dev.A*** creates a branch "uncommentStep3" ("uncommentStep4" for ***Dev.B***)
2. Checkout to the new branch, and check it to make sure
```
git branch
```
3. ***Dev.A*** deletes comments of *Step 3*
4. Commit the modifications and merge it to main branch
```
git checkout main
git merge uncommentStep3
```
5. push it to remote and try to get the same workflow one gitk 

## 5. Manage conflicts 
1. ***Dev.B*** creates a new branch "PCG".
2. ***Dev.B*** uncomments *Step 6.1* and **delete** *Step 6.2*.
3. ***Dev.B*** commits this modification and merge it main. 
4. ***Dev.B*** publishes it to remote.
5. ***Dev.A*** creates a new branch "CG".
6. ***Dev.A*** uncomments *Step 6.2* and **delete** *Step 6.1*.
7. ***Dev.A*** commits this modification.
8. ***Dev.A*** checkout to main.
9. ***Dev.A*** does a git pull to update his local main branch
10. ***Dev.A*** merge branch "CG" to main.  
11. ***Dev.A*** publishes it to remote.

> Here ***Dev.A*** has to handle the conflicts when merge "CG" to main. You can choose either PCG or CG. 

## 6. Manage remote
1. ***Dev.B*** creates an annotated tag named "V1.0"
```
git tag -a v1.0 -m "version 1.0"
```
2. ***Dev.B*** publishes this tag to remote
```
git push origin v1.0 
```
3. Check tag in remote
4. ***Dev.A*** fetches this tag to his local and check it on gitk
5. ***Dev.A*** creates a private empty project in Koda.
6. ***Dev.A*** creates also a private empty project in Koda.
7. Both publish their project to Koda. 

## Checkout from a specific commit 
1. Both do a checkout from your first commit obtained in section "Commit and push" and give a name to this branch "addContent"
```
git checkout -b addContent Hash (Hash: commit ID)
```
2. Both uncomment "Step 7", and commit this modifications. 
```
git commit -a -m "uncomment Step 7"
```
3. ***Dev.A*** adds the following line before "Step 1" in "main.cpp" and commit it
```
std::cout<<"This is a iterative solvor to solve Ax=b"<<endl;
```
```
git commit -a -m "add solvor description"
```
4. ***Dev.B*** adds the following line before ```return 0``` in "main.cpp"
```
std::cout<<"Problem solved!"<<endl;
```
```
git commit -a -m "add end line"
```
5. Both delete the line ```/*******Step 1 ********/``` 
6. Both try to merge the fastest commit to main. 
```
git checkout main
```
```
git cherry-pick hash
```
Both do a ```git pull``` than ```git push```. 
> You may need ```git stash``` to switch to branch main