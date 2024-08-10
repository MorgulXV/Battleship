#!/bin/zsh

# Hole die installierte CMake-Version
installed_version=$(cmake --version | grep version | awk '{print $3}')
echo "Gefundene CMake-Version: $installed_version"

# Optional: Setze das Verzeichnis, in dem gesucht werden soll, auf das aktuelle Verzeichnis
search_dir="."

# Funktion, um rekursiv nach relevanten Dateien zu suchen und die Version zu aktualisieren
update_version() {
  local dir=$1

  # Finde alle relevanten Dateien im aktuellen Verzeichnis und seinen Unterverzeichnissen
  find "$dir" \( -name "CMakeLists.txt" -o -name "Makefile" -o -name "CMakeCache.txt" \) | while read -r file; do
    echo "Verarbeite $file..."

    # Finde die aktuelle cmake_minimum_required-Version im File
    current_version=$(grep -o "cmake_minimum_required(VERSION [0-9]\+\.[0-9]\+\.[0-9]\+)" "$file" | awk '{print $3}')

    if [ -z "$current_version" ]; then
      # Versuche eine andere Methode, um eine Version zu finden
      current_version=$(grep -o "version [0-9]\+\.[0-9]\+\.[0-9]\+" "$file" | awk '{print $2}')
    fi

    if [ -n "$current_version" ]; then
      echo "Gefundene Version in $file: $current_version"

      # Ersetze die gefundene Version durch die installierte CMake-Version
      sed -i '' "s/$current_version/$installed_version/g" "$file"

      echo "Ersetzte $current_version durch $installed_version in $file"
    else
      echo "Keine CMake-Version in $file gefunden."
    fi
  done
}

# Starte die Aktualisierung
update_version "$search_dir"

echo "Alle relevanten Dateien wurden aktualisiert."
