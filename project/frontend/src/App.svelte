<script>
  import { Router, Link, Route } from "svelte-routing";
  //   import { push } from "svelte-spa-router";
  //   export let notes;
  import Login from "./Login.svelte";
  import Todo from "./Todo.svelte";
</script>

<Router>
  <nav>
    <Link to="">login</Link>
    <Link to="todo">todo</Link>
  </nav>
  <main>
    <Route path="" component={Login} />
    <Route path="todo" component={Todo} />
  </main>
</Router>

<!-- <main>
  <Home />
</main>

<style>
  main {
    background-color: rgb(255, 251, 246);
    padding: 2em;
    width: 100%;
    height: 100%;
    overflow-y: auto;
  }
</style> -->
