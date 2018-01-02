+#!/usr/bin/env python
+# -*- coding: utf-8 -*-
+
+def horner_rek(k, tab[], x):
+    if (k == 0):
+        return tab[0] * x
+    return horner_rek(k - 1; tab, x) * x + tab[k]
+
+
+def main(args):
+
+
+    return 0
+
+
+if _name_ == '_main_':
+    import sys
+    sys.exit(main(sys.argv))
