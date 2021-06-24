pcc 编译器

# How To Dev
## first. create dev env
```sh
docker run -d \
--net host \
--privileged  \
-v  $HOME/src:/root/src \
--name cpp-dev-env \
fightinggg/cpp-dev-env \
bash -c "while true; do sleep 100; done;"
```
## second. enjoy your self in project
```sh
mkdir build && cd build && cmake .. && make && cd ..
./build/pcc
```

# How To Use


