{
  description = "raytracing project from when back when I was a student";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      deps = with pkgs; [
        gnumake
        gcc13
        csfml
        glibc
      ];

      mkCApp = name: pkgs.stdenv.mkDerivation rec {
        inherit name;
        src = ./.;

        makeFlags = [ "CC=${pkgs.gcc13}/bin/gcc" ];
        buildInputs = deps;

        hardeningDisable = [ "format" "fortify" ];
        enableParallelBuilding = true;

        buildPhase = ''
          make
        '';

	# TODO: find out where default configs can be put using $out
        installPhase = ''
          mkdir -p $out/bin
          cp ${name} $out/bin
        '';
      };
    in
    {
      packages.${system} = {
        default = mkCApp "raytracer2";
      };

      formatter.${system} = pkgs.nixpkgs-fmt;
      devShells.${system}.default =
        pkgs.mkShell
          {
            buildInputs = with pkgs; [
              bat
              gnumake
              gcc13
              csfml
              glibc
            ];

            shellHook = ''
              echo "hello mom"
            '';
          };
    };
}
