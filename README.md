# Simple C++ backend login with Drogon Framework

<hr>
<p align="center">This repo still under development</p>
<hr>

## Setup

1. Drogon Framework
   
   First is required to have an instalation of **drogon** with the mysql/mariadb connector available. Check the [installation wiki](https://drogonframework.github.io/drogon-docs/#/ENG-02-Installation?id=drogon-installation) to get details.
   
```
❯ drogon_ctl --version
     _
  __| |_ __ ___   __ _  ___  _ __
 / _` | '__/ _ \ / _` |/ _ \| '_ \
| (_| | | | (_) | (_| | (_) | | | |
 \__,_|_|  \___/ \__, |\___/|_| |_|
                 |___/

A utility for drogon
Version: 1.9.2
Git commit: baea2dce47172e7aaab67b20e6a4887a1f6464cf
Compilation: 
  Compiler: c++
  Compiler ID: GNU
  Compilation flags: -std=c++17 -I/usr/include -I/usr/local/include
Libraries: 
  postgresql: yes  (pipeline mode: yes)
  mariadb: yes
  sqlite3: yes
  ssl/tls backend: OpenSSL
  brotli: yes
  hiredis: no
  c-ares: yes
  yaml-cpp: no
```

2. Database setup
   
   In this example I used mariadb running in the machine. To work this you need to create an user in the mariadb for the application with permission to use a database and tables.

```txt
dbuser: drogon
dbpassword: drogon
dbname: drogondb
dbtable: user in drogondb database
```

This database settings should be in the config.json in the project root and in the model.json inside models folder. The model.json is used by drogon to create a header and source file based on each table in the database with this command (executed from the project root folder where is the models folder):

```bash
drogon_ctl create model models
```

In this case, the files are allready generated. If you want to test this,  to create the table for the user model I used this:

```sql
CREATE TABLE user(id INT NOT NULL AUTO_INCREMENT,first_name VARCHAR(30) NOT NULL, last_name VARCHAR(30) NOT NULL, username VARCHAR(20) NOT NULL, password BINARY(60) NOT NULL, PRIMARY KEY(id));
```

Then run the command to create the models and you should have the files created.

3. Compile the project
   
   Just compile with cmake
   
```bash
mkdir build
cd build
cmake ..
make
```

Your should have the executable ready to run with **./drogon-auth-sample**.

## Test

This example expose the login api for authentication. This return a session cookie for authorized endpoints. (Not implemented here). This example just compare the password strings just for demostration. This require BCrypt real comparation.

-> Login URL: `localhost:8080/api/v1/auth/login`
-> Body(raw/json)

```json
{"username":"myusername","password":"samePasswordInDb"}
```

## ToDo

* Implemen BCrypt for a real login password validation.
* Implement `signup` and `logout`

