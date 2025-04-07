FROM ubuntu:22.04

# Evita prompts de instalación
ENV DEBIAN_FRONTEND=noninteractive

# Instala herramientas necesarias
RUN apt-get update && \
    apt-get install -y build-essential git curl python3 python3-pip && \
    apt-get clean

# Clona Francinette y configura sus dependencias
RUN git clone https://github.com/xicodomingues/francinette.git /francinette && \
    pip3 install -r /francinette/requirements.txt

# Directorio de trabajo
WORKDIR /app

# Comando por defecto: bash interactivo
CMD ["/bin/bash"]
