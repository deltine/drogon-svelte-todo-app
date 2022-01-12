<script>
  import Router from "svelte-spa-router";
  import { link, location } from "svelte-spa-router";
  import routes from "./routes";

  function routeLoaded(event) {
    console.log("event: " + event);
  }
</script>

<Router {routes} on:routeLoaded={routeLoaded} />

<style>
</style>
