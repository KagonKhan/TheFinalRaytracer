script_folder="/home/sszynk/projects/templates/build/Debug/generators"
echo "echo Restoring environment" > "$script_folder/deactivate_conanbuildenv-debug-x86_64.sh"
for v in ACLOCAL_PATH
do
   is_defined="true"
   value=$(printenv $v) || is_defined="" || true
   if [ -n "$value" ] || [ -n "$is_defined" ]
   then
       echo export "$v='$value'" >> "$script_folder/deactivate_conanbuildenv-debug-x86_64.sh"
   else
       echo unset $v >> "$script_folder/deactivate_conanbuildenv-debug-x86_64.sh"
   fi
done

export ACLOCAL_PATH="$ACLOCAL_PATH:/home/sszynk/.conan2/p/xorg-a7814e7f591fa/p/bin/share/aclocal"