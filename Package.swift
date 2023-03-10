import PackageDescription

let package = Package(
    name: "Map GL Native",
    products: [
        .library(
            name: "Mapbox",
            targets: ["Mapbox"])
    ],
    dependencies: [
    ],    
    targets: [
        .binaryTarget(
            name: "Mapbox",
            path: "Mapbox.xcframework")
    ]
)
