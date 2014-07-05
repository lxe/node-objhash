{
  "targets": [
    {
      "target_name": "objhash",
      "sources": ["src/objhash.cc"],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}