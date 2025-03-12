# A small project to practice git 
In this exercise, you’ll work with a Python script (`TP.py`), uncomment sections step-by-step by removing `#` before each line, commit changes, and run the script to see the output. The project runs in GitHub Codespaces and focuses on Git essentials with immediate feedback. The script starts empty and grows as you uncomment sections—perfect for learning Git workflows collaboratively.

Work in pairs (***Dev.A*** and ***Dev.B***) to achieve efficiency.
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
- Set your name and email
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
- Set VS Code as the default editor:
```bash
git config --global core.editor "code --wait"
```
> The `--wait` flag ensures Git waits for VS Code to close before proceeding.
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
git config --global alias.loggraph "log --all --decorate --oneline --graph"
git config --global alias.log1 "log --oneline"
```
> These shorten `git status` to `git st`, `git commit` to `git ci`,`git branch` to `git br` and add visual logs with `git loggraph` and `git log1`
- Verify your settings
```bash
git config --global --list
```
## 1. Fork the project
You don’t have write access to this repo, so fork it. Only one fork per pair!

- ***Dev.B***: Fork the project by clicking on the fork button in the upper right corner of the project page.

- Now ***Dev.B*** has his own copy of the project. In order to give ***Dev.A*** write permissions to the project,
- ***Dev.B*** needs to add ***Dev.A*** to the project’s list of collaborators: *Settings -> Collaborators*.

## 2. Clone the repository
In this part, ***Dev.B*** does the same thing as ***Dev.A***
- clone the remote to local and then go to the local repository 
```bash
git clone YourRemoteRepository
cd GitTP
```
- Visualize the workflow:
```bash
git loggraph
```
or by "Graph"
- Test the initial (empty) script:
```bash
python TP.py
```
> No output yet, since everything is commented out.
## 3. Commit and push
- ***Both*** check the status of this git repository
```
git statut
```
- ***Both*** Uncomment Step 1 (the "Welcome..." line), save and run it.
```bash
git statut
python TP.py
```
- ***Both*** stage the modifications (check graph)
```bash
git add TP.py
```
- ***Both*** commit this modifications 
```bash
git commit -m "uncomment Step 1 for A and uncomment Step 2 for B"
```
check graph

- ***Both*** push this commit
```bash
git push
```
> One of the teammates will find that it is not possible to push the modifications. Try to figure it out. 

> Tips: The teammate pushed after the first need to do `git pull` before the `git push`

- Try to get the same output for graph when finished. 

## 4. Branch and merge
- ***Dev.A***:
  - Create and checkout branch:
    ```bash
    git checkout -b Step2
    ```
  - Verify 
    ```bash
    git branch
    ```
  - Uncomment Step 2 (remove # from "def subtract..." and "print..."), save and run it.
  - Commit it 
    ```bash
    git add TP.py
    git ci -m "uncomment Step 2"
    ```
  - Create a new file ***dev_A_tools.py***:
  - Copy and paste this content into ***dev_A_tools.py***
   ```python
        # dev_A_tools.py
        def greet(name):
        return f"Hello, {name}!"
   ```
   - Update ***TP.py*** to use the function.
   - After Step 2, add:
   ```python
        from dev_A_tools import greet
        print(greet("Dev.A"))
   ```
  - Save and run.
  - Stage and commit
    ```bash
    git add TP.py dev_A_tools.py
    git ci -m "add greet function in dev_A_tools.py"
    ```
  - Merge to main and publish it
    ```bash
    git checkout main
    git pull
    git merge Step2
    git push
    ```
> Do not forget to check often with status and graph 
- ***Dev.B***:
  - Create and checkout branch:
    ```bash
    git checkout -b Step3
    ```
  - Verify 
    ```bash
    git branch
    ```
  - Uncomment Step 3, save and run it.
  - Commit it 
    ```bash
    git add TP.py
    git ci -m "uncomment Step 3"
    ```
  - Create a new file ***dev_B_tools.py***:
  - Copy and paste this content into ***dev_B_tools.py***
   ```python
        # dev_B_tools.py
        def square(number):
        return number * number
   ```
   - Update ***TP.py*** to use the function.
   - After Step 2, add:
   ```python
        from dev_B_tools import greet
        print("Square of 4:", square(4))
   ```
  - Save and run.
  - Stage and commit
    ```bash
    git add TP.py dev_B_tools.py
    git ci -m "add square function in dev_B_tools.py"
    ```
  - Merge to main and publish it
    ```bash
    git checkout main
    git pull
    git merge uncommentStep3
    git push
    ```
- ***Both*** try to get the same workflow on graph 

## 5. Manage conflicts 
- ***Dev.B***
    - create a new branch "uncommentStep4".
    - uncomment "Step 4", save and run it.
    - commit this modification and merge it to main branch. 
    - publish it to remote.
- ***Dev.A***
    - create a new branch "changeStep4".
    - uncomment "Step 4" and **change** the output from "Great job completing the steps!" to "Congratulations!"
    - Save and run it.
    - commit these modifications.
    - checkout to main.
    - do a `git pull` to update local main branch
    - merge branch "changeStep4" to main.  
    - publish it to remote.
    - Resolve conflict:
    ```bash
    git mergetool
    ```

> Here ***Dev.A*** has to handle the conflicts when merge "changeStep4" to main.  

## 6. Manage remote
- ***Dev.B***
    - create an annotated tag named "V1.0"
        ```bash
        git tag -a v1.0 -m "version 1.0"
        ```
    - publish this tag to remote
        ```bash
        git push origin v1.0 
        ```
    - Check tag in remote
- ***Dev.A*** 
    - fetche this tag to his local and check it on graph
- ***Both***
    - create a private empty project in Koda.
    - publish the project to Koda. 

## Fix a Bug and Cherry-Pick
In this part, you’ll check out an earlier commit, fix a bug in a new branch, and use `git cherry-pick` to apply the fix to `main`. This simulates fixing a mistake from the past and bringing the solution forward without merging an entire branch.
- ***Both***
    - Look for a commit like "uncomment Step 2"
    ```bash
    git log1
    ```
    - Checkout that commit into a new branch:
    ```bash
    git checkout -b fix-subtract-bug Hash (Hash: commit ID)
    ```
    - Check files that you have in your repository 
    ```bash
    ls 
    ```
    - change `return a + b` in the `Step 2` of `TP.py` to `return a - b`
    - save and run it
    - commit it if it is right
    ```bash
    git add TP.py
    git ci -m "fix subtract bug: change + to -"
    ```
    - Merge this ***commit*** to `main` branch
    ```bash
    git checkout main
    git pull
    git cherry-pick <fix-hash>
    ```
<!-- 
2. Both uncomment "Step 7", and commit this modifications. 
```
git commit -a -m "uncomment Step 7"
```
3. ***Dev.A*** adds the following line before "Step 1" in "TP.py" and commit it
```
std::cout<<"This is a iterative solvor to solve Ax=b"<<endl;
```
```
git commit -a -m "add solvor description"
```
4. ***Dev.B*** adds the following line before `return 0` in "TP.py"
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
> You may need ```git stash``` to switch to branch main -->