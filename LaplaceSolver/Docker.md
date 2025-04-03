apt update
apt-get install gcc g++ git make wget gpg -y
apt update
wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB | gpg --dearmor | tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
echo "deb [trusted=yes] https://apt.repos.intel.com/oneapi all main" | tee /etc/apt/sources.list.d/oneAPI.list
apt update
apt install intel-oneapi-base-toolkit -y
source /opt/intel/oneapi/setvars.sh intel64